select h.name,h.num_beds - ifnull(sum(o.beds_occupied ),0) as empty_beds_count,ifnull(sum(o.beds_occupied),0) * 100.0 / h.num_beds as pct_occupied 
from hospitals h
left join occupancy o on o.hospital_id = h.id
where h.state = 'New York'
group by h.id,h.name,h.num_beds
order by pct_occupied DESC;