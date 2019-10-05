#include <iostream>

static const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = ( char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;

}

std::string base64_decode(std::string const& encoded_string) {
  size_t in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]) & 0xff;

      char_array_3[0] = ( char_array_4[0] << 2       ) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) +   char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = 0; j < i; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]) & 0xff;

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}

int main() {
  const std::string s = 
    "com.global.secure.phone.call";

  std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
  std::string decoded = base64_decode(encoded);

  std::cout << "encoded: " << std::endl << encoded << std::endl << std::endl;
  std::cout << "decoded: " << std::endl << decoded << std::endl;


  // Test all possibilites of fill bytes (none, one =, two ==)
  // References calculated with: https://www.base64encode.org/

  std::string rest0_original = "com.us.free.phone.number";
  std::string rest0_reference = "com.us.free.phone.number";

  std::string rest0_encoded = base64_encode(reinterpret_cast<const unsigned char*>(rest0_original.c_str()),
    rest0_original.length());
  std::string rest0_decoded = base64_decode(rest0_encoded);

  std::cout << "encoded:   " << rest0_encoded << std::endl;
  std::cout << "reference: " << rest0_reference << std::endl;
  std::cout << "decoded:   " << rest0_decoded << std::endl << std::endl;


  std::string rest1_original = "free.call.international.phone.wifi.calling";
  std::string rest1_reference = "free.call.international.phone.wifi.calling";

  std::string rest1_encoded = base64_encode(reinterpret_cast<const unsigned char*>(rest1_original.c_str()),
    rest1_original.length());
  std::string rest1_decoded = base64_decode(rest1_encoded);

  std::cout << "encoded:   " << rest1_encoded << std::endl;
  std::cout << "reference: " << rest1_reference << std::endl;
  std::cout << "decoded:   " << rest1_decoded << std::endl << std::endl;


  std::string rest2_original = "free.call.international.phone.calling";
  std::string rest2_reference = "free.call.international.phone.calling";

  std::string rest2_encoded = base64_encode(reinterpret_cast<const unsigned char*>(rest2_original.c_str()),
    rest2_original.length());
  std::string rest2_decoded = base64_decode(rest2_encoded);

  std::cout << "encoded:   " << rest2_encoded << std::endl;
  std::cout << "reference: " << rest2_reference << std::endl;
  std::cout << "decoded:   " << rest2_decoded << std::endl << std::endl;

    std::string rest3_original = "com.whatsphone.messenger.im";
    std::string rest3_reference = "com.whatsphone.messenger.im";
    
    std::string rest3_encoded = base64_encode(reinterpret_cast<const unsigned char*>(rest3_original.c_str()),
                                              rest3_original.length());
    std::string rest3_decoded = base64_decode(rest2_encoded);
    
    std::cout << "encoded:   " << rest3_encoded << std::endl;
    std::cout << "reference: " << rest3_reference << std::endl;
    std::cout << "decoded:   " << rest3_decoded << std::endl << std::endl;
  return 0;
}
