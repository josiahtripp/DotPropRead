# DotPropRead

Format of loaded file:

    All keys corresponding to the .properties file are stored
    within the "string * keys" array.
    All values associated with the file are stores within the
    "string * values" array.
        -If there is more than one value associated with a key,
         it will be stored within the same element as the other values.
        -These values will be stored one after another, and are delimited
         by null characters.
        -Null character separate all values, placed only between values.
        - For > 0 values, the number of values within the array element 
          is equal to the number of null characters + 1.
        -In the event of a key having no associated value(s), a null character
         will be placed within the values array. The character is indexed at 0 
         of the string, and is the only charchter within it.
        

Errors:

123 - Key cannot be located;
173 - No value is associated with the requested key