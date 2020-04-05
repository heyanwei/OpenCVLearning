srv=person-detection

docker:
	docker build . -t ${srv}:latest

	docker tag ${srv} wilsonhe2019/${srv}
	docker push wilsonhe2019/${srv}

rundocker:
	docker run wilsonhe2019/${srv}