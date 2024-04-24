
This code will output:


#### Using String Split Method

Alternatively, if you prefer not to use the `os` module or are working with a string that is not a file path, you can use the `split` method of strings.

```python
path = '/opt/home/etc/sample'
base_name = path.split('/')[-1]

print(base_name)
sample
