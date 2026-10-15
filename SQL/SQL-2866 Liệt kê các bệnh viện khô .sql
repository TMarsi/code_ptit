SELECT h.name, h.capacity
FROM hospitals h
WHERE NOT EXISTS ( SELECT 1 
    FROM patient_vaccinations p
    WHERE p.hospital_id = h.id
      AND p.date >= '2022-03-01'
      AND p.date < '2022-04-01'
)
ORDER BY h.name;