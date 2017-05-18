"""

Write code that, given `my_str`, returns True if that string is a palindrome,
and False otherwise.

A palindrome is a word/phrase that is the same backwards as forwards (e.g. "race car").
Single-letter strings (e.g. "I") should be considered palindromes

You may assume that the input is a valid, lower-case string. However, the string
might have white-space, which you should remove.

HINT: If the first and last letters don't match, you know for a fact that the string
can't be a palidrome. Use your control flow tools to make your code more efficient
by stopping execution as soon as you know the answer.

"""

def my_function(my_str):
    """ Parameters
        ----------
        my_str : str
            The word/phrase to be analyzed

        Returns
        -------
        True if my_str is a palindrome, False otherwise.
    """
    # Remove "pass" and add your code here
    my_str = my_str.replace(" ", "")
    for i in range(0, len(my_str) // 2):
        if my_str[i] != my_str[len(my_str) - i - 1]:
            return False
    return True
