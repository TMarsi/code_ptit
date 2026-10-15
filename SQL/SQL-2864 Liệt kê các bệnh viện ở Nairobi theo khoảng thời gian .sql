SELECT h.name, COUNT(DISTINCT p.patient_id) AS unique_patients, COUNT(p.id) AS total_shots
FROM hospitals h
LEFT JOIN patient_vaccinations p ON p.hospital_id = h.id AND p.date >= '2022-03-01' AND p.date < '2022-04-01'
WHERE h.location = 'Nairobi'
GROUP BY h.id, h.name
ORDER BY unique_patients DESC, total_shots DESC;