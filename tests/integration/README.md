# DCAF Integration Tests

These integration tests require a running local DCAF instance.

## Requirements

Create and activate a virtual environment, then install the Python packages used by the tests:

```bash
python3 -m venv .venv
source .venv/bin/activate
python3 -m pip install pytest httpcore pydantic
```

## Start DCAF

From `docker/local`, start the local DCAF stack:

```bash
cd ~/rt-data-collection-application-function/docker/local
docker compose up --build
```

Keep the stack running while executing the tests. The exposed DCAF APIs are:

- R1 Provisioning API: port `5000`
- R2 Direct Data Reporting API: port `5100`
- R6 Event Exposure API: port `5201`

These are the default ports from the local Docker setup. If your port mappings differ, update the corresponding addresses and ports in `config.toml` before running the tests.

## Run Tests

```bash
pytest -v -s ~/rt-data-collection-application-function/tests/integration/test_dcaf_crud.py
```
