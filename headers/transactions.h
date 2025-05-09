// Includes transaction and command structures and their definitions

#pragma once

#include "database.h"
#include "server.h"
#include "config.h"
#include "resp.h"
#include "auth.h"

#include <stdbool.h>
#include <stdint.h>

// TRANSACTIONS
struct Transaction {
  struct Client *client;
  commanddata_t data;
  struct Command *command;
  struct Password *password;
  struct Database *database;
};

void create_transaction_thread(struct Configuration *config);
void deactive_transaction_thread();

uint64_t get_processed_transaction_count();
uint32_t get_transaction_count();
bool add_transaction(struct Client *client, struct Command *command, commanddata_t data);
void remove_transaction(struct Transaction *transaction);
void free_transactions();



// COMMANDS
#define WRONG_ARGUMENT_ERROR(client, name, len) (_write((client), "-Wrong argument count for '" name "' command\r\n", 38 + (len)))
#define MISSING_SUBCOMMAND_ERROR(client, name, len) (_write((client), "-Missing subcommand for '" name "' command\r\n", 36 + (len)))
#define INVALID_SUBCOMMAND_ERROR(client, name, len) (_write((client), "-Invalid subcommand for '" name "' command\r\n", 36 + (len)))

struct CommandEntry {
  struct Database *database;
  struct Client *client;
  struct Password *password;
  commanddata_t *data;
};

struct Subcommand {
  char *name;
  char *summary;
  char *since;
  char *complexity;
};

struct Command {
  char *name;
  char *summary;
  char *since;
  char *complexity;
  uint64_t permissions;
  void (*run)(struct CommandEntry entry);
  struct Subcommand *subcommands;
  uint32_t subcommand_count;
};

void execute_command(struct Transaction *transaction);

struct Command *load_commands();
struct Command *get_commands();
uint32_t get_command_count();
void free_commands();
