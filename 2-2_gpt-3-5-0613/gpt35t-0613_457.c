
You are using the variables `ind`, `count`, `newcount` to calculate the correct indices for accessing the `newi` and `newj` arrays. However, this calculation is incorrect and hence causing the issue.

To correctly assign values from `newi` and `newj` to `ri` and `ci`, you need to use the correct index calculation. Here's the corrected loop:

```csharp
for(int ind=count-newcount; ind<count; ind++)
{
    ri[ind] = newi[ind-(count-newcount)];
    ci[ind] = newj[ind-(count-newcount)];
}
