from pathlib import Path
import tomllib

from pydantic import BaseModel


class DcafEndpoint(BaseModel):
    protocol: str
    address: str
    port: int

    @property
    def base_url(self) -> str:
        return f"{self.protocol}://{self.address}:{self.port}"


class Settings(BaseModel):
    dcaf_r1: DcafEndpoint
    dcaf_r2: DcafEndpoint
    dcaf_r6: DcafEndpoint


with (Path(__file__).parent / "config.toml").open("rb") as config_file:
    raw_config = tomllib.load(config_file)

settings = Settings(
    dcaf_r1=raw_config["dcaf-R1"],
    dcaf_r2=raw_config["dcaf-R2"],
    dcaf_r6=raw_config["dcaf-R6"],
)