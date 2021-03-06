##
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
##

from pycylon.data.aggregates cimport CGroupByAggregationOp

cpdef enum AggregationOp:
    SUM = CGroupByAggregationOp.CSUM
    COUNT = CGroupByAggregationOp.CCOUNT
    MIN = CGroupByAggregationOp.CMIN
    MAX = CGroupByAggregationOp.CMAX
    VAR = CGroupByAggregationOp.CVAR
    NUNIQUE = CGroupByAggregationOp.CNUNIQUE
    MEAN = CGroupByAggregationOp.CMEAN
    QUANTILE = CGroupByAggregationOp.CQUANTILE
    STDDEV = CGroupByAggregationOp.CSTDDEV

AggregationOpString = {
    'sum': CGroupByAggregationOp.CSUM,
    'cnt': CGroupByAggregationOp.CCOUNT,
    'min': CGroupByAggregationOp.CMIN,
    'max': CGroupByAggregationOp.CMAX,
    'var': CGroupByAggregationOp.CVAR,
    'nunique': CGroupByAggregationOp.CNUNIQUE,
    'mean': CGroupByAggregationOp.CMEAN,
    'quantile': CGroupByAggregationOp.CQUANTILE,
    'std': CGroupByAggregationOp.CSTDDEV,
}
