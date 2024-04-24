...
while (1) // while service_charge_list ALL
{
    if(i >= len) {
        break;
    }
    // Check for the end of service_charge_list (simple heuristic approach based on '],')
    // This is a fragile way to determine the end and may not work in all cases.
    if(text[i] == ']' && text[i+1] == ',') {
        break; // Attempting to break out of the parsing loop for service_charge_list
    }
    if(text[i] == 'f' && text[i+1] == 'r' && text[i+2] == 'o' && text[i+3] == 'm') {
    ... // your existing code
