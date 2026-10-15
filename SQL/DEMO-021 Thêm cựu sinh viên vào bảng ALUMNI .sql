insert into ALUMNI(SID,FullName)
select SID,FullName
from Student
where Graduated = 1;