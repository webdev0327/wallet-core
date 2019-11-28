// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "WalletConsole.h"
#include "CommandExecutor.h"
#include "Keys.h"
#include "Coins.h"
#include "Util.h"
#include "Address.h"
#include "TonCoin.h"

#include "Base64.h"
#include "HexCoding.h"
#include "Data.h"

#include <iostream>
#include <vector>
#include <cassert>

namespace TW::WalletConsole {

using namespace std;
using namespace TW;


void WalletConsole::init() {
    _outst << endl;
    _outst << "Wallet-core Console                          (c) TrustWallet" << endl;
    _outst << "Type 'help' for list of commands." << endl;
    _outst << endl;

    _executor.init();
}

void WalletConsole::loop() {
    while (true) {
        _outst << "> ";
        string line;
        getline(_inst, line);
        Util::trimLeft(line);
        if (line.length() == 0) { continue; }
        if (isExit(line)) {
            break;
        }

        _executor.executeLine(line);
    }
    _outst << "Bye!" << endl << endl;
}

bool WalletConsole::isExit(const string& line) {
    if (line.length() < 4) return false;
    string first4 = line.substr(0, 4);
    if (first4 == "quit" || first4 == "exit") { return true; }
    return false;
}

} // namespace TW::WalletConsole
