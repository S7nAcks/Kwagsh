// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2018, The Kwagsh Developers
//
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

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {  
  {23010, "563fdfc14f9e4892f16eb06291d264f8d9f6e8d6c06c4277fafb265201a902ef"},  
     {3600, "91ff3617ba9ef06800c5ecb041bb1ced24052b433f49b1cec580a5a3f5f62c3a"},
     {4000, "b41e369ee54178abd1f965bc5b85f3761962ef648d61233824781f554ed51280"},
     {5000, "0605c26b3626453d4d0a10a036aa2381f2a50890d8f87fb5304161f504a3abe5"},
     {6000, "1f28e170251038abe1b1ded5be86d0fa0bb1e944ac1bf90b20833a7e054032a1"},
     {7000, "47a59932f123d4f20d64b20e102b0656c8e68376944fe0872fd3c4778456e5ee"},
     {10000, "e69b60ae79c1e800df9ece1d718dbf327c902b46aba7cfbb9992d708d93e00b9"},
     {11000, "76a8084cff3f445301bfd3ba233dd894ee04b392ceb1e8e2538029123afb0feb"},
     {13500, "20e2823833f0d5fe7583062f0cc1fab2f5d3699db3dce69cee82e9cdd0dc5460"},
     {20000, "4feb6d7996bb3b67c2554a16f64b7bb18f14fa07963c4ab2755d3bbf927ef983"},
     {35000, "3793e84ff953ff12ff5c0074d75c1ff067660be7cb54b30ff0611782b135de83"},
     {40000, "a9a06c3ac8550c5b1e28b6699628583ed1bd18b1e602695776bb926b4de15d4e"},
     {40044, "0822a63706bbe2e6e359324c320230ecd1b1641b0568a6e361eadc3bf5e982e5"},
     {40500, "121f5c5271955feda03075cf6d232bf56df131cb6674cb5aaa62f1651146cd41"},
     {40700, "f881961202dab3345cb62ef20dab2d7446aac63ca4f5b7614ff4bda40415a06a"},
     {41110, "50857465520e20b54a62a59c495c26ceb67ebc583786c589e08be44967d4ed8e"},
     {41111, "8834c5f59d88ff47068a38f1178dc9cf9f8847e4534651a8954d0ff259d35787"},
     {41179, "f16aa6ba0adfcf095e29a18647a166c816d4975563030f1fbaf022dcf6d02b87"},
     {41180, "d346451a726012977080bb541e2f1706ecf4df434feee48d9dcf8a8e39c6b278"}
};
}
