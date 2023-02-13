/*
	test.cpp
	Copyright (c) 2023 Daniel H. All rights reserved

	Inital encode/decode implementation
	Copyright (c) 2004-2017, 2020-2022 René Nyffenegger

	This source code is provided 'as-is', without any express or implied
	warranty.In no event will the author be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter itand redistribute it
	freely, subject to the following restrictions :

	1. The origin of this source code must not be misrepresented; you must not
	   claim that you wrote the original source code.If you use this source code
	   a product, an acknowledgment in the product documentation would be
	   appreciated but is not required.

	2. Altered source versions must be plainly marked as such, and must not be
	   misrepresented as being the original source code.

	3. This notice may not be removed or altered from any source distribution.

	Daniel H. (daaniel08@protonmail.com)
*/
#include <iostream>
#include "../base64.h"

// Track the current mismatches
int mismatches = 0;
int totalMissmatch = 0;

const size_t testSize = 18;

struct TestSet {
	const char* input;
	const char* base64;
};

TestSet testSet[testSize] = {
	{ "cc", "Y2M=" },
	{ "41fb", "NDFmYg==" },
	{ "1f877c", "MWY4Nzdj" },
	{ "c1ecfdfc", "YzFlY2ZkZmM=" },
	{ "21f134ac57", "MjFmMTM0YWM1Nw==" },
	{ "c6f50bb74e29", "YzZmNTBiYjc0ZTI5" },
	{ "119713cc83eeef", "MTE5NzEzY2M4M2VlZWY=" },
	{ "4a4f202484512522", "NGE0ZjIwMjQ4NDUxMjUyMg==" },
	{ "1f66ab4185ed9b6375", "MWY2NmFiNDE4NWVkOWI2Mzc1" },
	{ "eed7422227613b6f53c9", "ZWVkNzQyMjIyNzYxM2I2ZjUzYzk=" },
	{ "eaeed5cdffd89dece455f1", "ZWFlZWQ1Y2RmZmQ4OWRlY2U0NTVmMQ==" },
	{ "5be43c90f22902e4fe8ed2d3", "NWJlNDNjOTBmMjI5MDJlNGZlOGVkMmQz" },
	{ "a746273228122f381c3b46e4f1", "YTc0NjI3MzIyODEyMmYzODFjM2I0NmU0ZjE=" },
	{ "3c5871cd619c69a63b540eb5a625", "M2M1ODcxY2Q2MTljNjlhNjNiNTQwZWI1YTYyNQ==" },
	{ "fa22874bcc068879e8ef11a69f0722", "ZmEyMjg3NGJjYzA2ODg3OWU4ZWYxMWE2OWYwNzIy" },
	{ "52a608ab21ccdd8a4457a57ede782176", "NTJhNjA4YWIyMWNjZGQ4YTQ0NTdhNTdlZGU3ODIxNzY=" },
	{ "82e192e4043ddcd12ecf52969d0f807eed", "ODJlMTkyZTQwNDNkZGNkMTJlY2Y1Mjk2OWQwZjgwN2VlZA==" },
	{ "75683dcb556140c522543bb6e9098b21a21e", "NzU2ODNkY2I1NTYxNDBjNTIyNTQzYmI2ZTkwOThiMjFhMjFl" },
};

int main(int argc, char* argv[]) {
	std::cout << "Running test with test set size of: " << testSize << std::endl << std::endl;

	// Test the BASE64 Encoding

	std::cout << "Running BASE64 Test #1 (Encoding)" << std::endl;

	BASE64 base64;
	std::string data;

	for (int i = 0; i < testSize; i++) {
		// Compare the result and the encoded result
		if (strcmp(testSet[i].base64, base64.encode(testSet[i].input).c_str()) != 0) {
			std::cout << "[WARNING] Mismatch on BASE64 encoding! Input: '" << testSet[i].input << "'; BASE64: '" << testSet[i].base64 << "';" << std::endl;
			mismatches++;
		}
	}

	std::cout << "Finished BASE64 Test #1 (Encoding) with " << mismatches << " total mismatches" << std::endl << std::endl;
	totalMissmatch += mismatches;
	mismatches = 0;

	// Test the BASE64 Decoding

	std::cout << "Running BASE64 Test #2 (Decoding)" << std::endl;

	for (int i = 0; i < testSize; i++) {
		// Compare the result and the decoded result
		if (strcmp(testSet[i].input, base64.decode(testSet[i].base64).c_str()) != 0) {
			std::cout << "[WARNING] Mismatch on base64 decoding! Input: '" << testSet[i].base64 << "'; BASE64: '" << testSet[i].input << "';" << std::endl;
			mismatches++;
		}
	}

	std::cout << "Finished BASE64 Test #2 (Decoding) with " << mismatches << " total mismatches" << std::endl << std::endl;
	totalMissmatch += mismatches;
	mismatches = 0;


	// Test the BASE64 Streaming Option (Encoding)

	std::cout << "Running BASE64 Test #3 (Stream Encoding)" << std::endl;

	base64.reset();

	base64.add("Hello");
	base64.add("World");

	if (strcmp(base64.encode().c_str(), base64.encode("HelloWorld").c_str()) != 0) {
		std::cout << "[WARNING] Mismatch on base64 stream encoding" << std::endl;
	}

	std::cout << "Finished BASE64 Test #3 (Stream Encoding) with " << mismatches << " total mismatches" << std::endl << std::endl;
	totalMissmatch += mismatches;
	mismatches = 0;

	// Test the BASE64 Streaming Option (Decoding)

	std::cout << "Running BASE64 Test #4 (Stream Decoding)" << std::endl;

	base64.reset();

	base64.add(base64.encode("Some random string"));

	if (strcmp(base64.decode().c_str(), base64.decode(base64.encode("Some random string")).c_str()) != 0) {
		std::cout << "[WARNING] Mismatch on base64 stream decoding" << std::endl;
	}

	std::cout << "Finished BASE64 Test #4 (Stream Decoding) with " << mismatches << " total mismatches" << std::endl << std::endl;
	totalMissmatch += mismatches;
	mismatches = 0;

	std::cout << "Testing done, total mismatch count: 0" << std::endl;

	return EXIT_SUCCESS;
}
