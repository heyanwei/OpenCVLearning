srv=person-detection

cleanlog:
	rm -r build/log

valgrind:
	cd build && valgrind --leak-check=yes ./person-srv

docker:
	docker build . -t ${srv}:latest

	docker tag ${srv} wilsonhe2019/${srv}
	# docker push wilsonhe2019/${srv}

rundocker:
	docker run wilsonhe2019/${srv}