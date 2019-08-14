/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

/**[info]
 * This file contains source code for basic helper macros used for code-generator.
 */

#ifndef oatpp_macro_ForEach_hpp
#define oatpp_macro_ForEach_hpp

#define OATPP_MACRO_FOREACH_EXAMPLE_FUNC(INDEX, COUNT, X) \
ENV::log("macro", "param: %d/%d: '%s'", INDEX, COUNT, #X);

#define OATPP_MACRO_FOREACH_EXAMPLE(...) OATPP_MACRO_FOREACH(OATPP_MACRO_FOREACH_EXAMPLE_FUNC, (__VA_ARGS__))

#define OATPP_MACRO__NUM_ARGS(X100, X99, X98, X97, X96, X95, X94, X93, X92, X91, X90, X89, X88, X87, X86, X85, X84, X83, X82, X81, X80, X79, X78, X77, X76, X75, X74, X73, X72, X71, X70, X69, X68, X67, X66, X65, X64, X63, X62, X61, X60, X59, X58, X57, X56, X55, X54, X53, X52, X51, X50, X49, X48, X47, X46, X45, X44, X43, X42, X41, X40, X39, X38, X37, X36, X35, X34, X33, X32, X31, X30, X29, X28, X27, X26, X25, X24, X23, X22, X21, X20, X19, X18, X17, X16, X15, X14, X13, X12, X11, X10, X9, X8, X7, X6, X5, X4, X3, X2, X1, N, ...)   N

#define OATPP_MACRO_NUM_ARGS(...) OATPP_MACRO__NUM_ARGS(__VA_ARGS__, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

#define OATPP_MACRO_HAS_ARGS_ARR(...) OATPP_MACRO__NUM_ARGS(__VA_ARGS__, true, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0)


//////////////////////////////////////////////////////////////////////////////////////////////////
// BEGIN(Detect empty macro)
// Please note:
// this code is taken from
// https://gustedt.wordpress.com/2010/06/08/detect-empty-macro-arguments/
//////////////////////////////////////////////////////////////////////////////////////////////////

// #define OATPP_MACRO_HAS_ARGS(...) OATPP_MACRO_HAS_ARGS_ARR(L, ##__VA_ARGS__)

#define OATPP_MACRO_TRIGGER_PARENTHESIS_(...) ,

#define OATPP_MACRO_ISEMPTY(...) \
OATPP_MACRO_ISEMPTY_( \
/* test if there is just one argument, eventually an empty one */ \
OATPP_MACRO_HAS_ARGS_ARR(__VA_ARGS__), \
/* test if OATPP_MACRO_TRIGGER_PARENTHESIS_ together with the argument adds a comma */ \
OATPP_MACRO_HAS_ARGS_ARR(OATPP_MACRO_TRIGGER_PARENTHESIS_ __VA_ARGS__), \
/* test if the argument together with a parenthesis adds a comma */ \
OATPP_MACRO_HAS_ARGS_ARR(__VA_ARGS__ (/*empty*/)), \
/* test if placing it between OATPP_MACRO_TRIGGER_PARENTHESIS_ and the parenthesis adds a comma */ \
OATPP_MACRO_HAS_ARGS_ARR(OATPP_MACRO_TRIGGER_PARENTHESIS_ __VA_ARGS__ (/*empty*/)) \
)

#define OATPP_MACRO_PASTE5(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#define OATPP_MACRO_ISEMPTY_(_0, _1, _2, _3) OATPP_MACRO_HAS_ARGS_ARR(OATPP_MACRO_PASTE5(OATPP_MACRO_IS_EMPTY_CASE_, _0, _1, _2, _3))
#define OATPP_MACRO_IS_EMPTY_CASE_0001 ,

#define OATPP_MACRO_HAS_ARGS_NOT_1 0
#define OATPP_MACRO_HAS_ARGS_NOT_0 1
#define OATPP_MACRO_HAS_ARGS__(X) OATPP_MACRO_HAS_ARGS_NOT_ ## X
#define OATPP_MACRO_HAS_ARGS_(X) OATPP_MACRO_HAS_ARGS__(X)
#define OATPP_MACRO_HAS_ARGS(...) OATPP_MACRO_HAS_ARGS_(OATPP_MACRO_ISEMPTY(__VA_ARGS__))


//////////////////////////////////////////////////////////////////////////////////////////////////
// END(Detect empty macro)
//////////////////////////////////////////////////////////////////////////////////////////////////

#define OATPP_MACRO_CONCAT(X,Y) OATPP_MACRO_CONCAT(X,Y)
#define OATPP_MACRO_CONCAT2(X,Y) X##Y
#define OATPP_MACRO_CONCAT_2 OATPP_MACRO_CONCAT
#define OATPP_MACRO_CONCAT_3(X,Y,Z) OATPP_MACRO_CONCAT(X,OATPP_MACRO_CONCAT(Y,Z))

#define OATPP_MACRO_STR(X) #X

#define OATPP_MACRO_EXPAND(X) X
#define OATPP_MACRO_FIRSTARG(X, ...) X
#define OATPP_MACRO_FIRSTARG_STR(X, ...) #X
#define OATPP_MACRO_RESTARGS(X, ...) (__VA_ARGS__)

#define OATPP_MACRO_FIRSTARG_EXPAND(X, ...) OATPP_MACRO_FIRSTARG X

#define OATPP_MACRO_UNFOLD_VA_ARGS(...) __VA_ARGS__

/////////

#define OATPP_MACRO_MACRO_SELECTOR_CALL(X, Y) OATPP_MACRO_CONCAT2(X, Y)
#define OATPP_MACRO_MACRO_SELECTOR(MACRO, PARAMS_LIST) OATPP_MACRO_MACRO_SELECTOR_CALL(MACRO, OATPP_MACRO_NUM_ARGS PARAMS_LIST)

#define OATPP_MACRO_MACRO_BINARY_SELECTOR(MACRO, PARAMS_LIST) OATPP_MACRO_MACRO_SELECTOR_CALL(MACRO, OATPP_MACRO_HAS_ARGS_ARR PARAMS_LIST)

/////////

#define OATPP_MACRO_MACRO_OR_EMPTY_0(MACRO, LIST)
#define OATPP_MACRO_MACRO_OR_EMPTY_1(MACRO, LIST) MACRO

#define OATPP_MACRO_MACRO_OR_EMPTY_(X, MACRO, LIST) \
OATPP_MACRO_MACRO_OR_EMPTY_##X(MACRO, LIST)

#define OATPP_MACRO_MACRO_OR_EMPTY__(X, MACRO, LIST) \
OATPP_MACRO_MACRO_OR_EMPTY_(X, MACRO, LIST)

#define OATPP_MACRO_MACRO_OR_EMPTY___(MACRO, LIST) \
OATPP_MACRO_MACRO_OR_EMPTY__(OATPP_MACRO_HAS_ARGS LIST, MACRO, LIST)

#define OATPP_MACRO_MACRO_OR_EMPTY(MACRO, ...) \
OATPP_MACRO_MACRO_OR_EMPTY___(MACRO, (__VA_ARGS__))

//////////

#define OATPP_MACRO_FOREACH_OR_EMPTY_0(MACRO, LIST)
#define OATPP_MACRO_FOREACH_OR_EMPTY_1(MACRO, LIST) OATPP_MACRO_FOREACH(MACRO, LIST)

#define OATPP_MACRO_FOREACH_OR_EMPTY_(X, MACRO, LIST) \
OATPP_MACRO_FOREACH_OR_EMPTY_##X(MACRO, LIST)

#define OATPP_MACRO_FOREACH_OR_EMPTY__(X, MACRO, LIST) \
OATPP_MACRO_FOREACH_OR_EMPTY_(X, MACRO, LIST)

#define OATPP_MACRO_FOREACH_OR_EMPTY___(MACRO, LIST) \
OATPP_MACRO_FOREACH_OR_EMPTY__(OATPP_MACRO_HAS_ARGS LIST, MACRO, LIST)

#define OATPP_MACRO_FOREACH_OR_EMPTY(MACRO, LIST) \
OATPP_MACRO_FOREACH_OR_EMPTY___(MACRO, LIST)

#define OATPP_MACRO_FOREACH_FIRST_AND_REST_(FIRST_MACRO, FIRST_ARG, MACRO, LIST) \
FIRST_MACRO(0, 0, FIRST_ARG) OATPP_MACRO_FOREACH_OR_EMPTY(MACRO, LIST)

#define OATPP_MACRO_FOREACH_FIRST_AND_REST(FIRST_MACRO, MACRO, LIST) \
OATPP_MACRO_FOREACH_FIRST_AND_REST_(FIRST_MACRO, OATPP_MACRO_FIRSTARG LIST, MACRO, OATPP_MACRO_RESTARGS LIST)

/////////

#define OATPP_MACRO_FOREACH(MACRO, LIST) OATPP_MACRO_FOREACH_(OATPP_MACRO_NUM_ARGS LIST, MACRO, LIST)
#define OATPP_MACRO_FOREACH_(N, M, LIST) OATPP_MACRO_FOREACH__(N, M, LIST)
#define OATPP_MACRO_FOREACH__(N, M, LIST) OATPP_MACRO_FOREACH_##N(N, M, LIST)

#define OATPP_MACRO_FOREACH_CALL(INDEX, COUNT, MACRO, PARAM) MACRO(INDEX, COUNT, PARAM)
#define OATPP_MACRO_FOREACH_1(N, M, LIST) OATPP_MACRO_FOREACH_CALL(N - 1, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))

#define OATPP_MACRO_FOREACH_2(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 2, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_1(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_3(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 3, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_2(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_4(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 4, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_3(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_5(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 5, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_4(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_6(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 6, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_5(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_7(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 7, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_6(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_8(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 8, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_7(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_9(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 9, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_8(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_10(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 10, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_9(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_11(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 11, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_10(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_12(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 12, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_11(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_13(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 13, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_12(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_14(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 14, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_13(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_15(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 15, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_14(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_16(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 16, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_15(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_17(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 17, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_16(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_18(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 18, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_17(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_19(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 19, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_18(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_20(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 20, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_19(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_21(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 21, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_20(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_22(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 22, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_21(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_23(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 23, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_22(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_24(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 24, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_23(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_25(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 25, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_24(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_26(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 26, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_25(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_27(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 27, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_26(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_28(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 28, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_27(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_29(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 29, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_28(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_30(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 30, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_29(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_31(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 31, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_30(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_32(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 32, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_31(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_33(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 33, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_32(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_34(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 34, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_33(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_35(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 35, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_34(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_36(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 36, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_35(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_37(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 37, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_36(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_38(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 38, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_37(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_39(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 39, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_38(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_40(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 40, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_39(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_41(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 41, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_40(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_42(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 42, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_41(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_43(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 43, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_42(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_44(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 44, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_43(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_45(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 45, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_44(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_46(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 46, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_45(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_47(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 47, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_46(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_48(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 48, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_47(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_49(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 49, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_48(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_50(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 50, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_49(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_51(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 51, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_50(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_52(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 52, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_51(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_53(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 53, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_52(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_54(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 54, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_53(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_55(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 55, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_54(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_56(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 56, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_55(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_57(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 57, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_56(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_58(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 58, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_57(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_59(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 59, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_58(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_60(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 60, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_59(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_61(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 61, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_60(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_62(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 62, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_61(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_63(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 63, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_62(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_64(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 64, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_63(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_65(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 65, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_64(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_66(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 66, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_65(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_67(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 67, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_66(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_68(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 68, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_67(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_69(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 69, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_68(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_70(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 70, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_69(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_71(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 71, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_70(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_72(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 72, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_71(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_73(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 73, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_72(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_74(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 74, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_73(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_75(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 75, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_74(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_76(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 76, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_75(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_77(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 77, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_76(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_78(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 78, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_77(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_79(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 79, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_78(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_80(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 80, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_79(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_81(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 81, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_80(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_82(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 82, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_81(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_83(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 83, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_82(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_84(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 84, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_83(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_85(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 85, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_84(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_86(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 86, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_85(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_87(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 87, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_86(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_88(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 88, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_87(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_89(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 89, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_88(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_90(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 90, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_89(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_91(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 91, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_90(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_92(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 92, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_91(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_93(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 93, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_92(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_94(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 94, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_93(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_95(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 95, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_94(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_96(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 96, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_95(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_97(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 97, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_96(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_98(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 98, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_97(N, M, OATPP_MACRO_RESTARGS LIST)

#define OATPP_MACRO_FOREACH_99(N, M, LIST)  \
OATPP_MACRO_EXPAND(OATPP_MACRO_FOREACH_CALL(N - 99, N, M, OATPP_MACRO_FIRSTARG_EXPAND(LIST))) \
OATPP_MACRO_FOREACH_98(N, M, OATPP_MACRO_RESTARGS LIST)


#endif /* oatpp_macro_ForEach_hpp */
