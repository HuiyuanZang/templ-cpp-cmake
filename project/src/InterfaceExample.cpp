/*
 * Copyright (c) 2022 Harvest Technology Group Pty Ltd. All Rights Reserved.
 * @file InterfaceExample.cpp
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


#include "InterfaceExample.hpp"
#include "InternalExample.hpp"

namespace MyAPI {

class InterfaceExample::InterfaceImpl {
 public:
    std::string GetMessage() { return _hello.append(_example.GetName()); }

 private:
    std::string _hello = "Hello World! ";

    HiddenImplementation::InternalExample _example;
};

InterfaceExample::InterfaceExample() : _impl(new InterfaceExample::InterfaceImpl()) {}

InterfaceExample::~InterfaceExample() = default;

std::string InterfaceExample::GetHelloWorld() const { return _impl->GetMessage(); }

}  // namespace MyAPI