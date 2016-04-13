# AndroidKeypadSearch

Phone dialer on a phone can be used to dial a phone number or search a contact.<br>
The keypad input represents a number, and also all possible combinations of alphabets represented by the keys.<br>
For example, 726 represents a part of phone number and also all possible names like Sam, Ram, Rao etc.<br>
The dialer outputs names of such people in phone book along with their phone number.
<br><br>This program is simple version of dial pad search.<br>

### Data Structure and Algorithm

The program is using Trie data structure to store the contact information.<br>
It is explained below.<br>

#### To insert, do the following
1. The chars in name are converted to the corresponding digits. For e.g., "Raj" is changed to "725"<br>
2. This changed name is passed to Trie data structure and the contact object is stored at the leaf node. Here, it is 5.<br>
3. At the leaf node, the contact object is stored in `vector`. Because multiple names can have same digits. For eg, "Ram" and "Sam".<br>
4. Store the same contact using phone number as well in the Trie. So that if any of the name or phone number matches, the contact will show up.<br>

#### To search user input
1. Travese the Trie using the user input.
2. If at any point, we get `NULL`, we return from there. As there are no entry for the user input.
3. Traverse to leaf node of user input. From there find all the contact information.<br>
4. Store the contact object in `set`. Set is used to remove duplicates. We are storing the same contact using first name, last name and phone number. So, we can find the same contact from multiple path.<br>
5. Output the set to the user.<br>

### Unit Test

1. Checkout this project.
2. From the base directory, run the following command
```bash
$ make clean
$ make tester
$ ./bin/tester
```
