/**
 * MIT License
 *
 * Copyright (c) 2020 Rajdeep Roy Chowdhury
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include "util.h"
#include "splitwebp.h"
int main(int argc, const char* argv[]) {
    if (argc == 1) {
        splitwebp::Util::showHelp();
    } else if (argc == 2) {
        if (std::strcmp(argv[1], "--help") * std::strcmp(argv[1], "-h") == 0) {
            splitwebp::Util::showHelp();
        } else if (std::strcmp(argv[1], "--version") * std::strcmp(argv[1], "-v") == 0) {
            splitwebp::Util::showHelp();
        } else {
            splitwebp::SplitWebP splitWebP(argv[1]);
            if (!splitWebP.load()) {
                splitwebp::Util::printError("Error in loading");
                return EXIT_FAILURE;
            }
            if (!splitWebP.produce()) {
                splitwebp::Util::printError("Error in exporting images");
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}