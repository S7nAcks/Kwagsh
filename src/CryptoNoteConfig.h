// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero project
// Copyright (c) 2018, The Qwertycoin project
// Copyright (c) 2014-2018, The Forknote developers
// Copyright (c) 2016-2018, The Karbowanec developers
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

#pragma once

#include <cstdint>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x5ec8; // addresses start with "aaQ"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const size_t   CRYPTONOTE_TX_SPENDABLE_AGE                   = 6;

const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = DIFFICULTY_TARGET * 60;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V1         = DIFFICULTY_TARGET * 11; 
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V1          = 11; 

const uint64_t MONEY_SUPPLY                                  = (uint64_t)(-1);
const uint64_t TAIL_EMISSION_REWARD                          =  100000000;
const size_t CRYPTONOTE_COIN_VERSION                         = 1;
const unsigned EMISSION_SPEED_FACTOR                         = 18;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000); // 0.001 KG
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000);    // 0.001
const uint64_t MIN_TX_MIXIN_SIZE                             = 1;
const uint64_t MAX_TX_MIXIN_SIZE							               = 20;
const uint64_t MAX_TRANSACTION_SIZE_LIMIT                    = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 / 4 - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE;

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = 70;  // blocks
const size_t   DIFFICULTY_WINDOW_V3                          = 70;  // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;  // !!!
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 1000000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24 ;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 2; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 2;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1 * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 23000;
const uint32_t UPGRADE_HEIGHT_V3                             = 54900;
const uint32_t UPGRADE_HEIGHT_V4                             = 4294967294;

const unsigned UPGRADE_VOTING_THRESHOLD                      = 80; // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "kwagsh";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff0001ffffffffffff0f029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101b63d849a9bb5e73fb88f22897698fd681ffa04c875876c22e165be582791c976";
const char     GENESIS_COINBASE_TX_FIX[]                     = "013c01ff0001ffffffffffff07029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101eddf1e272c1ffa70f49ca4eaad918578bc3b59689e53e48a1bc670fbdea08478.2.2";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  25386;
const int      RPC_DEFAULT_PORT                              =  25387;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const uint32_t P2P_FAILED_ADDR_FORGET_SECONDS                = (60 * 60);     //1 hour
const uint32_t P2P_IP_BLOCKTIME                              = (60 * 60 * 24);//24 hour
const uint32_t P2P_IP_FAILS_BEFORE_BLOCK                     = 10;
const uint32_t P2P_IDLE_CONNECTION_KILL_INTERVAL             = (5 * 60);      //5 minutes

const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "04414c9a60d7aa541b502edf74169946a110cc698efee14771f04eb05529495a3a91c0862d11b402bafab4a179997f432e17decc04943910d54e27e74d2524c034";

const char* const SEED_NODES[] = { 
    "80.211.12.28:25386",
  "80.211.163.119:25386",
  "94.177.164.118:25386",
  "194.182.87.111:25386",
  "81.2.240.84:25386"
};

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
     {41111, "8834c5f59d88ff47068a38f1178dc9cf9f8847e4534651a8954d0ff259d35787"}

};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
