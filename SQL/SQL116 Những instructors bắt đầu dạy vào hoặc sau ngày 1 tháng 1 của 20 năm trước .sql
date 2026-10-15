select *
from Instructor
where started_on >= CONCAT(YEAR(CURDATE()) - 20, '-01-01');