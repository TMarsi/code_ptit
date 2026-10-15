SELECT
    h.name,
    h.capacity,
    COUNT(p.id) AS total_shots_mar2022,
    ROUND(100.0 * COUNT(p.id) / h.capacity, 2) AS utilization_pct
FROM hospitals h
JOIN patient_vaccinations p
    ON h.id = p.hospital_id
WHERE p.date >= '2022-03-01'
  AND p.date < '2022-04-01'
GROUP BY h.id, h.name, h.capacity
ORDER BY utilization_pct DESC;