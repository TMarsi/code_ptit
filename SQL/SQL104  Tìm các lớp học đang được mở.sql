select c.title
from Class c,Teaches t
where c.dept = t.dept and c.number = t.number