
2. Manually parsing a JSON string is error-prone and cumbersome. Use a JSON parsing library for C like cJSON or jansson.

3. You're looking for an explicit "service_charge_list" string which leads you into a loop to process service charges, but you're not managing the exit condition correctly to return back to the main loop. It appears you're stuck in an infinite loop because there's nothing to break the loop when you reach the end of a service_charge_list.

4. `menunum_charge` is always 0. As per the code, you never increment it causing all service charges to overwrite each other in the array at index 0.

To solve your issues:

- Fix your JSON to be valid.
- Implement appropriate control breaks to prevent infinite loops.
- Use a JSON parser library to deserialize the JSON string into your struct arrays.

However, if you want to stick with your manual parsing approach (not recommended for production), then you need to figure out how to properly manage your parsing state to correctly populate your structs, especially when you begin to parse service charges. This requires careful design of your semantic actions in response to each element you parse, and checking your parsing state to know when to exit loops.
