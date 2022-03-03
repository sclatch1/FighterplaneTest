//
// Created by david Scalais on 03/03/2022.
//

#ifndef TICTACTOE_DESIGNBYCONTRACT2_H
#define TICTACTOE_DESIGNBYCONTRACT2_H
#include <assert.h>

#define REQUIRE(assertion, what) \
if (!(assertion)) __assert (what, __FILE__, __LINE__)

#define ENSURE(assertion, what) \
if (!(assertion)) __assert (what, __FILE__, __LINE__)
#endif //TICTACTOE_DESIGNBYCONTRACT2_H
