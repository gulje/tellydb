// Includes all definitions
#pragma once

#define VERY_LIKELY(x) (__builtin_expect_with_probability(!!(x), 1, 0.999))
#define VERY_UNLIKELY(x) (__builtin_expect_with_probability(!!(x), 0, 0.999))

#include "auth.h" // IWYU pragma: export
#include "btree.h" // IWYU pragma: export
#include "commands.h" // IWYU pragma: export
#include "config.h" // IWYU pragma: export
#include "database.h" // IWYU pragma: export
#include "hashtable.h" // IWYU pragma: export
#include "resp.h"  // IWYU pragma: export
#include "server.h" // IWYU pragma: export
#include "transactions.h" // IWYU pragma: export
#include "utils.h" // IWYU pragma: export
