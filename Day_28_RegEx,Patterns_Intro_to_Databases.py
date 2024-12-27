'''
Consider a database table, Emails, which has the attributes First Name and Email ID. 
Given N rows of data simulating the Emails table, print an alphabetically-ordered list of people 
whose email address ends in @gmail.com .
'''

#!/bin/python3

import math
import os
import random
import re
import sys

# Function to check if an email is a Gmail address
def is_gmail(email):
    return email.endswith('@gmail.com')

if __name__ == '__main__':
    N = int(input().strip())
    gmail_users = []

    for N_itr in range(N):
        first_multiple_input = input().rstrip().split()

        firstName = first_multiple_input[0]

        emailID = first_multiple_input[1]
 # Check and store Gmail users
        if is_gmail(emailID):
            gmail_users.append(firstName)

    # Sort the names alphabetically
    gmail_users.sort()

    # Print the sorted names
    for name in gmail_users:
        print(name)