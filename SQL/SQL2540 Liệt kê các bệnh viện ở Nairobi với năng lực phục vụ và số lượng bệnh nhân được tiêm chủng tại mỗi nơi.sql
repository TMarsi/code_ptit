select h.name,h.capacity,count(p.id) as vaccinated
from hospitals h
join patient_vaccinations p on p.hospital_id = h.id
where h.location = 'Nairobi'
group by h.name,h.capacity