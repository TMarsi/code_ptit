SELECT
    cs.sector_name,
    us.union_status,
    AVG(wsi.incidents) AS avg_incidents_2021_2022
FROM workplace_safety_incidents wsi
JOIN construction_sectors cs
    ON wsi.sector_id = cs.sector_id
JOIN union_status us
    ON wsi.union_status_id = us.id
WHERE wsi.incident_year IN (2021, 2022)
GROUP BY cs.sector_id, cs.sector_name, us.id, us.union_status
ORDER BY avg_incidents_2021_2022 DESC
LIMIT 3;