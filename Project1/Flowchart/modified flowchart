flowchart TD
    A([Start]) --> B["Create Node Structure: Data, Prev, Next"]
    B --> C["Initialize top = NULL, front = rear = NULL"]
    C --> D["Display Main Menu"]
    D --> E{"Select Operation"}

    E -->|Stack| F{"Stack Operation"}
    E -->|Queue| G{"Queue Operation"}
    E -->|Exit| Z([Stop])

    F -->|Push| H["Create New Node"]
    H --> I["Insert Node at Top"]
    I --> J["Update Top Pointer"]
    J --> D

    F -->|Pop| K{"Stack Empty?"}
    K -->|Yes| L["Display Underflow"]
    K -->|No| M["Delete Top Node and Update Top"]
    L --> D
    M --> D

    F -->|Display| N["Traverse from Top to NULL"]
    N --> D

    G -->|Enqueue| O["Create New Node"]
    O --> P["Insert Node at Rear"]
    P --> Q["Update Front and Rear Pointers"]
    Q --> D

    G -->|Dequeue| R{"Queue Empty?"}
    R -->|Yes| S["Display Underflow"]
    R -->|No| T["Delete Front Node"]
    T --> U["Update Front and Prev Pointer"]
    U --> D
    S --> D

    G -->|Display| V["Traverse from Front to NULL"]
    V --> D
