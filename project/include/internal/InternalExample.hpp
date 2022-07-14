/*
 * Copyright (c) 2022 Harvest Technology Group Pty Ltd. All Rights Reserved.
 * @file InternalExample.hpp
 * @brief
 * @date 10/06/2022
 * @author Olesia Kochergina
 * @version
 * See the COPYRIGHT file at the top-level directory of this distribution for details of code ownership.
 * -----
 * Last Modified:
 * Modified By:
 * -----
 */


#ifndef INTERNAL_EXAMPLE_HPP
#define INTERNAL_EXAMPLE_HPP
#include <string>

namespace HiddenImplementation {
class InternalExample {
 public:
    InternalExample();

    ~InternalExample();

    std::string GetName() const;

 private:
    std::string _name = "I come from InternalExample";
};

}  // namespace HiddenImplementation
#endif