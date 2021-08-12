import requests
url = 'https://wttr.in/'
res = requests.get(url)
print(res.text)