// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018, The Kwagsh developers
//
// This file is part of Kwagsh.
//
// Kwagsh is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Kwagsh is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Kwagsh.  If not, see <http://www.gnu.org/licenses/>.

#include "StdInputStream.h"

namespace Common {

StdInputStream::StdInputStream(std::istream& in) : in(in) {
}

size_t StdInputStream::readSome(void* data, size_t size) {
  in.read(static_cast<char*>(data), size);
  return in.gcount();
}

}
