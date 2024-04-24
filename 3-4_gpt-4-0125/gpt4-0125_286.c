} else if(text[i] == '}' && text[i+1] == ']') { // Potentially marks end of service charge list
    // Increment to move past this point.
    i += 2; // Adjust based on actual requirements to safely move past the structure ending
    break; // Break from the inner loop to continue with the outer loop
}
