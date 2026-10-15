update Users
set name = concat(Upper(left(name,1)),lower(substring(name,2)))