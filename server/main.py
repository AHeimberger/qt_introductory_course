#!/usr/bin/env python3

from http.server import BaseHTTPRequestHandler, HTTPServer
import requests
import argparse


class TestServer(BaseHTTPRequestHandler):
    def __init__(self, appid, *args):
        self.appid = appid
        BaseHTTPRequestHandler.__init__(self, *args)

    def do_GET(self):
        new_path = self.path
        new_path = new_path.replace("YOUR_OPPENWEATHERMAP_APPID", self.appid)
        uri = "http://api.openweathermap.org{}".format(new_path)
        req = requests.get(uri)

        print("-"*100)
        print(req.url)
        print("-"*100)

        self.send_response(req.status_code)
        for item in req.headers.items():
            self.send_header(item[0], item[1])
        self.end_headers()
        self.wfile.write(req.content)


if __name__ == "__main__":
    hostName = "localhost"
    serverPort = 8000

    parser = argparse.ArgumentParser(description='Process some integers.')
    parser.add_argument('--appid', help='Add your AppId to run this application.')
    parser.add_argument('--port', type=int, help='Change port, default is {}'.format(serverPort), default=serverPort)
    parsed_args = parser.parse_args()

    if parsed_args.appid is None:
        parser.print_help()
        exit(1)
    
    def handler(*args):
        TestServer(parsed_args.appid, *args)

    serverPort = parsed_args.port

    webServer = HTTPServer((hostName, serverPort), handler)
    print("Server started http://%s:%s" % (hostName, serverPort))

    try:
        webServer.serve_forever()
    except KeyboardInterrupt:
        pass

    webServer.server_close()
    print("\nServer stopped.")
