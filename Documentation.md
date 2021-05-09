# Ciphers
**IMPORTANT** This library was built for 64-bit on Visual Studios 2019

All functions and the enum class in this library use the `ciphers::` namespace.

## Section 1 - Enum Class
To use the `Caeser()` and `Vigenere()` functions you will have to use the `ciphers::e_Choice` enum class.
The enum class contains two components: `e_Chocie::ENCODE` and `e_Chocie::DECODE`.

## Section 2 - Functions
### Caeser
The `Caeser()` function has two overrides with the **only** difference being the output destination of the result.

``` cpp
void Caeser(std::vector<char> inputText, std::vector<char>& output, short shift, e_Choice choice)
```

#### inputText
This is a char vector containing the text that you wish to encode or decode.

#### output
This is a reference to a char vector in which the encoded/decoded message will be stored.

#### shift
This is a short that tells the function what shift (*or key*) to use when encoding (*or that was used when decoding*).
This defaults to 3 when not specified.

#### choice
This tells the function whether you are encoding or decoding the input text and is set using the `ciphers::e_Choice` enum class explained in the previous section.
This defaults to `e_Choice::ENCODE` when not specified.

``` cpp
void Caeser(std::vector<char> inputText, std::ofstream& output, short shift, e_Choice choice)
```

#### inputText
This is a char vector containing the text that you wish to encode or decode.

#### output
This is a reference to an ofstream object in which the encoded/decoded message will be written.
**IMPORTANT:** The file must be opened outside of the function as the function does **NOT** open the file. If not opened the function will throw a runtime error.

#### shift
This is a short that tells the function what shift (*or key*) to use when encoding (*or that was used when decoding*).
This defaults to 3 when not specified.

#### choice
This tells the function whether you are encoding or decoding the input text and is set using the `ciphers::e_Choice` enum class explained in the previous section.
This defaults to `e_Choice::ENCODE` when not specified.

### Vigenere
The `Vigenere()` function has two overrides with the **only** difference being the output destination of the result.

``` cpp
void Vigenere(std::vector<char> inputText, std::vector<char>& output, std::vector<char> shift, e_Choice choice)
```

#### inputText
This is a char vector containing the text that you wish to encode or decode.

#### output
This is a reference to a char vector in which the encoded/decoded message will be stored.

#### shift
This is a char vector containing the word/phrase you wish to use when encoding (*or that was used when decoding*).

#### choice
This tells the function whether you are encoding or decoding the input text and is set using the `ciphers::e_Choice` enum class explained in the previous section.
This defaults to `e_Choice::ENCODE` when not specified.

``` cpp
void Vigenere(std::vector<char> inputText, std::ofstream& output, std::vector<char> shift, e_Choice choice)
```

#### inputText
This is a char vector containing the text that you wish to encode or decode.

#### output
This is a reference to an ofstream object in which the encoded/decoded message will be written.
**IMPORTANT:** The file must be opened outside of the function as the function does **NOT** open the file. If not opened the function will throw a runtime error.

#### shift
This is a char vector containing the word/phrase you wish to use when encoding (*or that was used when decoding*).

#### choice
This tells the function whether you are encoding or decoding the input text and is set using the `ciphers::e_Choice` enum class explained in the previous section.
This defaults to `e_Choice::ENCODE` when not specified.

### Atbash
The `Atbash()` function has two overrides with the **only** difference being the output destination of the result.

``` cpp
void Atbash(std::vector<char> inputText, std::vector<char>& output)
```

#### inputText
This is a char vector containing the text that you wish to encode or decode.

#### output
This is a reference to a char vector in which the encoded/decoded message will be stored.

``` cpp
void Atbash(std::vector<char> inputText, std::ofstream& output)
```

#### inputText
This is a char vector containing the text that you wish to encode or decode.

#### output
This is a reference to an ofstream object in which the encoded/decoded message will be written.
**IMPORTANT:** The file must be opened outside of the function as the function does **NOT** open the file. If not opened the function will throw a runtime error.
