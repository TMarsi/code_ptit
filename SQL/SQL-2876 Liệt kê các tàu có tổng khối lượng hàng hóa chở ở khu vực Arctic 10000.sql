select v.name, sum(vo.cargo_weight) as total_cargo_arctic
from vessels v
join voyages vo on v.id = vo.vessel_id
where vo.region = 'Arctic'
group by v.name
having sum(vo.cargo_weight) > 10000
order by total_cargo_arctic desc;