select max(vr.Horsepower) as horsepower
from Vehicle_Releases vr
join Vehicle_Types vt on vt.id = vr.Vehicle_Type_Id
where vt.Name = 'sedan' and year(vr.Release_Date) >= 2020;