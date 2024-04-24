
### Bash / Shell
```bash
#!/bin/bash

# String containing the path
path="/opt/home/etc/sample"

# Extract base name using basename command
base_name=$(basename "$path")

echo "$base_name"  # Output: sample

### JavaScript
In a JavaScript environment, such as Node.js, you can use the `path` module:
```javascript
const path = require('path');

// String containing the path
const filePath = "/opt/home/etc/sample";

// Extract base name
const baseName = path.basename(filePath);

console.log(baseName);  // Output: sample

### C#
```csharp
using System;
using System.IO;

class BaseNameExtractor
{
    static void Main()
    {
        string path = "/opt/home/etc/sample";
        
        // Extract base name
        string baseName = Path.GetFileName(path);
        
        Console.WriteLine(baseName);  // Output: sample
    }
}

Choose the example based on the language you are working with. Each example will give you the base name `sample` from the given string `/opt/home/etc/sample`.
