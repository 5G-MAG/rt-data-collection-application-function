"""
License: 5G-MAG Public License (v1.0)
Author: Erik Gaida
Copyright: (C) 2026 Fraunhofer  FOKUS
For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
"""

import httpcore
import json
from typing import Any
from pydantic import BaseModel


class HttpResponseError(Exception):
    def __init__(
        self,
        method: str,
        url: str,
        status: int,
        body: Any,
    ) -> None:
        self.method = method
        self.url = url
        self.status = status
        self.body = body
        super().__init__(f"{method} {url} returned HTTP {status}: {body}")


def setup_http2_pool() -> httpcore.ConnectionPool:
    return httpcore.ConnectionPool(http1=False, http2=True)

HTTP2_POOL = setup_http2_pool()


def request(
    method: str,
    url: str,
    payload: BaseModel | None = None,
) -> tuple[int, dict[str, str], dict[str, Any] | None]:
    headers = {"Content-Type": "application/json"} if payload else None
    content = (
        json.dumps(payload.model_dump(by_alias=True, exclude_none=True)).encode()
        if payload
        else None
    )

    response = HTTP2_POOL.request(method, url, headers=headers, content=content)

    body = json.loads(response.content) if response.content else None
    if not 200 <= response.status < 300:
        raise HttpResponseError(method, url, response.status, body)

    response_headers = {
        name.decode().lower(): value.decode()
        for name, value in response.headers
    }
    return response.status, response_headers, body