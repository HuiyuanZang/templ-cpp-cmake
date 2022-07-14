/*
 * Copyright (c) 2022 Harvest Technology Group Pty Ltd. All Rights Reserved.
 * @file InternalExample.cpp
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


#include "InternalExample.hpp"
#include <iostream>

namespace HiddenImplementation {

InternalExample::InternalExample() = default;

InternalExample::~InternalExample() = default;

std::string InternalExample::GetName() const { return _name; }

}  // namespace HiddenImplementation