select u.union_status,w.incident_year,sum(incidents) as total_incidents
from workplace_safety_incidents w
join construction_sectors c on w.union_status_id  = c.sector_id 
join union_status u on u.id = w.sector_id 
where w.incident_year >= 2021 and w.incident_year < 2023
group by u.id,u.union_status,incident_year
order by u.union_status,incident_year asc;