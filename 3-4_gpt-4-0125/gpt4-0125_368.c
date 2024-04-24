Start
Prompt user for input
Read the input as a string
If (the string contains exactly one '.' and all other characters are digits, with at least one digit before and one digit after '.') {
    If (the string is not a pure integer) {
        Convert the string to a floating-point number
        Display the floating-point number
    } else {
        Prompt "Invalid entry, integers are not allowed."
    }
} else {
    Prompt "Invalid entry, please enter a valid floating-point number."
}
