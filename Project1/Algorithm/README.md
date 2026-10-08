# Algorithm

## Blood Donor Management System Using Linked List

This project uses a singly linked list to manage blood donor records. The system allows users to add, delete, search, and display donor information.

## Algorithm

### Step 1: Start

Initialize the `head` pointer to `NULL`.

### Step 2: Display Menu

Display the following options:

1. Add Donor
2. Delete Donor
3. Search Donor
4. Display All Donors
5. Exit

### Step 3: Add Donor

- Create a new donor node dynamically.
- Enter the following donor details:
  - Donor ID
  - Name
  - Age
  - Blood Group
  - Contact Number
- Set the new node's `next` pointer to `head`.
- Update `head` to point to the new node.
- Display a success message.

### Step 4: Delete Donor

- Ask the user to enter the Donor ID.
- Traverse the linked list to find the donor.
- Keep track of both the current node and previous node.
- If the donor is not found, display "Donor not found."
- If the donor is the first node, update `head`.
- Otherwise, connect the previous node to the next node.
- Delete the selected node.
- Display a success message.

### Step 5: Search Donor

- Ask the user to enter the required blood group.
- Traverse the linked list.
- Compare each donor's blood group with the entered blood group.
- Display the details of all matching donors.
- If no matching donor is found, display "No suitable donor found."

### Step 6: Display All Donors

- Check whether the linked list is empty.
- If empty, display "No donor records available."
- Otherwise, traverse the complete linked list.
- Display the details of every donor.

### Step 7: Exit

If the user selects option 5, terminate the program.

### Step 8: Stop

End the program.

## Pseudocode

```text
START

Set HEAD = NULL

REPEAT

    Display Menu

    Read choice

    IF choice = 1
        Create new donor node
        Read donor details
        Insert node at beginning
        Display success message

    ELSE IF choice = 2
        Read Donor ID
        Search for donor
        IF donor found
            Remove donor node
            Delete node
        ELSE
            Display "Donor not found"
        END IF

    ELSE IF choice = 3
        Read Blood Group
        Traverse linked list
        Display donors with matching blood group
        IF no donor found
            Display "No suitable donor found"
        END IF

    ELSE IF choice = 4
        Traverse linked list
        Display all donor records

    ELSE IF choice = 5
        Display "Exiting program"

    ELSE
        Display "Invalid choice"

    END IF

UNTIL choice = 5

STOP
