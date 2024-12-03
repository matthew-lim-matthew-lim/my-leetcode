// 1. Initializing a new stringstream object
stringstream result;
// 2. Inserting a space into the stringstream
result << ' ';
// 3. Inserting the character at the specified index from the string `s`
result << s[stringIndex];
// 4. Converting the stringstream to a string
string finalString = result.str();