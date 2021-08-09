SELECT IFNULL(ROUND(COUNT(DISTINCT R.requester_id, R.accepter_id) / COUNT(DISTINCT F.sender_id, F.send_to_id), 2), 0.00) accept_rate
FROM friend_request F, request_accepted R





SELECT IFNULL(ROUND(
    (SELECT COUNT(*) FROM (SELECT DISTINCT requester_id, accepter_id FROM request_accepted) AS A) / 
    (SELECT COUNT(*) FROM (SELECT DISTINCT sender_id, send_to_id FROM friend_request) AS B), 2), 0.00)
accept_rate
