# Flowchart

## Blood Donor Management System Using Linked List

The following flowchart represents the working of the Blood Donor Management System.

```mermaid
flowchart TD
    A([Start]) --> B[Initialize HEAD = NULL]
    B --> C[Display Main Menu]

    C --> D{Enter Choice}

    D -->|1. Add Donor| E[Create New Donor Node]
    E --> F[Enter Donor Details]
    F --> G[Insert Node at Beginning]
    G --> H[Display Donor Added Successfully]
    H --> C

    D -->|2. Delete Donor| I[Enter Donor ID]
    I --> J[Search Donor in Linked List]
    J --> K{Donor Found?}
    K -->|No| L[Display Donor Not Found]
    L --> C
    K -->|Yes| M[Remove Node from Linked List]
    M --> N[Delete Node]
    N --> O[Display Donor Deleted Successfully]
    O --> C

    D -->|3. Search Donor| P[Enter Blood Group]
    P --> Q[Traverse Linked List]
    Q --> R{Blood Group Matches?}
    R -->|Yes| S[Display Donor Details]
    R -->|No| T[Continue Traversing]
    T --> Q
    S --> T
    T --> U{More Donors?}
    U -->|Yes| Q
    U -->|No| V{Any Donor Found?}
    V -->|No| W[Display No Suitable Donor Found]
    V -->|Yes| C
    W --> C

    D -->|4. Display All Donors| X{HEAD == NULL?}
    X -->|Yes| Y[Display No Donor Records Available]
    Y --> C
    X -->|No| Z[Traverse Linked List]
    Z --> AA[Display Donor Details]
    AA --> AB{More Donors?}
    AB -->|Yes| Z
    AB -->|No| C

    D -->|5. Exit| AC([Stop])

    D -->|Invalid Choice| AD[Display Invalid Choice]
    AD --> C
