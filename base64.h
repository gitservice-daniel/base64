/*
	base64.h
	Copyright (c) Daniel H. All rights reserved

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
#ifndef BASE64_H
#define BASE64_H

#include <string>

#ifdef _MSC_VER

typedef unsigned __int8  uint8_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;

#else // GCC, Clang, ...

#include <stdint.h>

#endif

/*
* Encode & Decode with BASE64
* 
* @Usage:
* > BASE64 base64;
* >
* > std::string myData = base64.encode("Hello World");
* > std::cout << myData << std::endl;
* > myData = base64.decode(data);
* >
* 
* Or use it with an streaming option:
* 
* @Usage
* > BASE64 base64;
* > while (dataflow) {
* >     base64.add("DATA");
* > }
* >
* > std::string data = base64.encode();
* > std::cout << data << std::endl;
* >
* 
* Streaming option is also with decode possible
* 
* @Usage
* > BASE64 base64;
* > while (dataflow) {
* >     base64.add(pointer to data, number of new bytes);
* > }
* >
* > std::string data = base64.decode();
* > std::cout << data << std::endl;
* >
* 
*/
class BASE64 {

	public: 

		// Encode a c++ string
		std::string encode(const std::string& text);

		// Encode the current stream
		std::string encode();

		// Decode a c++ string
		std::string decode(std::string data);

		// Decode the current stream
		std::string decode();

		// Add data to the current stream
		void add(std::string data);

		// Reset current stream
		void reset();

	private:

		// Current stream
		std::string stream = "";

};

#endif
