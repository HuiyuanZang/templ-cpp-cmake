/*
 * Copyright (c) 2022 Harvest Technology Group Pty Ltd. All Rights Reserved.
 * @file InterfaceExample.hpp
 * @brief
 * @date 01/03/2022
 * @author Olesia Kochergina
 * @version
 * See the COPYRIGHT file at the top-level directory of this distribution for details of code ownership.
 * -----
 * Last Modified:
 * Modified By:
 * -----
 */


#ifndef INTERFACE_EXAMPLE_HPP
#define INTERFACE_EXAMPLE_HPP
#include <memory>
#include <string>

namespace MyAPI {
class InterfaceExample {
 public:
    InterfaceExample();
    ~InterfaceExample();

    std::string GetHelloWorld() const;

 private:
    class InterfaceImpl;
    std::unique_ptr<InterfaceImpl> _impl;
};
}  // namespace MyAPI
#endif